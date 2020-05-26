# Automatically generated makefile, created by the Projucer
# Don't edit this file! Your changes will be overwritten when you re-save the Projucer project!

# build with "V=1" for verbose builds
ifeq ($(V), 1)
V_AT =
else
V_AT = @
endif

# (this disables dependency generation if multiple architectures are set)
DEPFLAGS := $(if $(word 2, $(TARGET_ARCH)), , -MMD)

ifndef STRIP
  STRIP=strip
endif

ifndef AR
  AR=ar
endif

ifndef CONFIG
  CONFIG=Debug
endif

JUCE_ARCH_LABEL := $(shell uname -m)

ifeq ($(CONFIG),Debug)
  JUCE_BINDIR := build
  JUCE_LIBDIR := build
  JUCE_OBJDIR := build/intermediate/Debug
  JUCE_OUTDIR := build

  ifeq ($(TARGET_ARCH),)
    TARGET_ARCH := 
  endif

  JUCE_CPPFLAGS := $(DEPFLAGS) -DLINUX=1 -DDEBUG=1 -D_DEBUG=1 -DJUCER_LINUX_MAKE_6D53C8B4=1 -DJUCE_APP_VERSION=0.1 -DJUCE_APP_VERSION_HEX=0x100 $(shell pkg-config --cflags alsa x11 xinerama xext freetype2 webkit2gtk-4.0 gtk+-x11-3.0 libcurl) -pthread -I../../JuceLibraryCode -I$(HOME)/JUCE/modules -I../../Include -I../../Include/KLU $(CPPFLAGS)

  JUCE_CPPFLAGS_STANDALONE_PLUGIN := -DJucePlugin_Build_VST=0 -DJucePlugin_Build_VST3=0 -DJucePlugin_Build_AU=0 -DJucePlugin_Build_AUv3=0 -DJucePlugin_Build_RTAS=0 -DJucePlugin_Build_AAX=0 -DJucePlugin_Build_Standalone=1 -DJucePlugin_Build_Unity=0
  JUCE_TARGET_STANDALONE_PLUGIN := Fuzzface

  JUCE_CPPFLAGS_SHARED_CODE := -DJucePlugin_Build_VST=0 -DJucePlugin_Build_VST3=0 -DJucePlugin_Build_AU=0 -DJucePlugin_Build_AUv3=0 -DJucePlugin_Build_RTAS=0 -DJucePlugin_Build_AAX=0 -DJucePlugin_Build_Standalone=1 -DJucePlugin_Build_Unity=0 -DJUCE_SHARED_CODE=1
  JUCE_TARGET_SHARED_CODE := Fuzzface.a

  JUCE_CFLAGS += $(JUCE_CPPFLAGS) $(TARGET_ARCH) -g -ggdb -O0 $(CFLAGS)
  JUCE_CXXFLAGS += $(JUCE_CFLAGS) -std=c++17 $(CXXFLAGS)
  JUCE_LDFLAGS += $(TARGET_ARCH) -L$(JUCE_BINDIR) -L$(JUCE_LIBDIR) $(shell pkg-config --libs alsa x11 xinerama xext freetype2 webkit2gtk-4.0 gtk+-x11-3.0 libcurl) -lrt -ldl -lpthread -lGL $(LDFLAGS)

  CLEANCMD = rm -rf $(JUCE_OUTDIR)/$(TARGET) $(JUCE_OBJDIR)
endif

ifeq ($(CONFIG),Release)
  JUCE_BINDIR := build
  JUCE_LIBDIR := build
  JUCE_OBJDIR := build/intermediate/Release
  JUCE_OUTDIR := build

  ifeq ($(TARGET_ARCH),)
    TARGET_ARCH := 
  endif

  JUCE_CPPFLAGS := $(DEPFLAGS) -DLINUX=1 -DNDEBUG=1 -DJUCER_LINUX_MAKE_6D53C8B4=1 -DJUCE_APP_VERSION=0.1 -DJUCE_APP_VERSION_HEX=0x100 $(shell pkg-config --cflags alsa x11 xinerama xext freetype2 webkit2gtk-4.0 gtk+-x11-3.0 libcurl) -pthread -I../../JuceLibraryCode -I$(HOME)/JUCE/modules -I../../Include -I../../Include/KLU $(CPPFLAGS)

  JUCE_CPPFLAGS_STANDALONE_PLUGIN := -DJucePlugin_Build_VST=0 -DJucePlugin_Build_VST3=0 -DJucePlugin_Build_AU=0 -DJucePlugin_Build_AUv3=0 -DJucePlugin_Build_RTAS=0 -DJucePlugin_Build_AAX=0 -DJucePlugin_Build_Standalone=1 -DJucePlugin_Build_Unity=0
  JUCE_TARGET_STANDALONE_PLUGIN := Fuzzface

  JUCE_CPPFLAGS_SHARED_CODE := -DJucePlugin_Build_VST=0 -DJucePlugin_Build_VST3=0 -DJucePlugin_Build_AU=0 -DJucePlugin_Build_AUv3=0 -DJucePlugin_Build_RTAS=0 -DJucePlugin_Build_AAX=0 -DJucePlugin_Build_Standalone=1 -DJucePlugin_Build_Unity=0 -DJUCE_SHARED_CODE=1
  JUCE_TARGET_SHARED_CODE := Fuzzface.a

  JUCE_CFLAGS += $(JUCE_CPPFLAGS) $(TARGET_ARCH) -O3 $(CFLAGS)
  JUCE_CXXFLAGS += $(JUCE_CFLAGS) -std=c++17 $(CXXFLAGS)
  JUCE_LDFLAGS += $(TARGET_ARCH) -L$(JUCE_BINDIR) -L$(JUCE_LIBDIR) $(shell pkg-config --libs alsa x11 xinerama xext freetype2 webkit2gtk-4.0 gtk+-x11-3.0 libcurl) -fvisibility=hidden -lrt -ldl -lpthread -lGL $(LDFLAGS)

  CLEANCMD = rm -rf $(JUCE_OUTDIR)/$(TARGET) $(JUCE_OBJDIR)
endif

OBJECTS_ALL := \

OBJECTS_STANDALONE_PLUGIN := \
  $(JUCE_OBJDIR)/include_juce_audio_plugin_client_Standalone_1a871192.o \

OBJECTS_SHARED_CODE := \
  $(JUCE_OBJDIR)/amd_1_1494b58.o \
  $(JUCE_OBJDIR)/amd_2_1494f19.o \
  $(JUCE_OBJDIR)/amd_aat_d6dfb23b.o \
  $(JUCE_OBJDIR)/amd_control_30e4b804.o \
  $(JUCE_OBJDIR)/amd_defaults_ee287a15.o \
  $(JUCE_OBJDIR)/amd_dump_b4cb837.o \
  $(JUCE_OBJDIR)/amd_global_c946b6a6.o \
  $(JUCE_OBJDIR)/amd_info_136f1c71.o \
  $(JUCE_OBJDIR)/amd_order_9e8d7635.o \
  $(JUCE_OBJDIR)/amd_post_tree_1b697604.o \
  $(JUCE_OBJDIR)/amd_postorder_659e6095.o \
  $(JUCE_OBJDIR)/amd_preprocess_f7034c2f.o \
  $(JUCE_OBJDIR)/amd_valid_f4490b63.o \
  $(JUCE_OBJDIR)/btf_maxtrans_dc4fa887.o \
  $(JUCE_OBJDIR)/btf_order_b7f53cb5.o \
  $(JUCE_OBJDIR)/btf_strongcomp_2e1bd2e9.o \
  $(JUCE_OBJDIR)/colamd_acf415a0.o \
  $(JUCE_OBJDIR)/klu_56af96e6.o \
  $(JUCE_OBJDIR)/klu_analyze_8ce64ab3.o \
  $(JUCE_OBJDIR)/klu_analyze_given_c20ff731.o \
  $(JUCE_OBJDIR)/klu_defaults_7047ef95.o \
  $(JUCE_OBJDIR)/klu_diagnostics_2d1d6613.o \
  $(JUCE_OBJDIR)/klu_dump_2682edb7.o \
  $(JUCE_OBJDIR)/klu_extract_e2bad0a8.o \
  $(JUCE_OBJDIR)/klu_factor_2e89c6d2.o \
  $(JUCE_OBJDIR)/klu_free_numeric_4c4387d.o \
  $(JUCE_OBJDIR)/klu_free_symbolic_6a04ecc.o \
  $(JUCE_OBJDIR)/klu_kernel_22c81640.o \
  $(JUCE_OBJDIR)/klu_memory_ea166604.o \
  $(JUCE_OBJDIR)/klu_refactor_ae035685.o \
  $(JUCE_OBJDIR)/klu_scale_a3f6e3b1.o \
  $(JUCE_OBJDIR)/klu_solve_b9109966.o \
  $(JUCE_OBJDIR)/klu_sort_3fc966e1.o \
  $(JUCE_OBJDIR)/klu_tsolve_a916cece.o \
  $(JUCE_OBJDIR)/SuiteSparse_config_58fabece.o \
  $(JUCE_OBJDIR)/ScopeComponent_11623c12.o \
  $(JUCE_OBJDIR)/SliderClass_9764dbf8.o \
  $(JUCE_OBJDIR)/PluginProcessor_a059e380.o \
  $(JUCE_OBJDIR)/PluginEditor_94d4fb09.o \
  $(JUCE_OBJDIR)/klu_solver_e0f4616c.o \
  $(JUCE_OBJDIR)/patch_static_ea5f4a73.o \
  $(JUCE_OBJDIR)/junctions_c30eb17b.o \
  $(JUCE_OBJDIR)/patch_82067c9.o \
  $(JUCE_OBJDIR)/BinaryData_ce4232d4.o \
  $(JUCE_OBJDIR)/include_juce_audio_basics_8a4e984a.o \
  $(JUCE_OBJDIR)/include_juce_audio_devices_63111d02.o \
  $(JUCE_OBJDIR)/include_juce_audio_formats_15f82001.o \
  $(JUCE_OBJDIR)/include_juce_audio_plugin_client_utils_e32edaee.o \
  $(JUCE_OBJDIR)/include_juce_audio_processors_10c03666.o \
  $(JUCE_OBJDIR)/include_juce_audio_utils_9f9fb2d6.o \
  $(JUCE_OBJDIR)/include_juce_core_f26d17db.o \
  $(JUCE_OBJDIR)/include_juce_cryptography_8cb807a8.o \
  $(JUCE_OBJDIR)/include_juce_data_structures_7471b1e3.o \
  $(JUCE_OBJDIR)/include_juce_events_fd7d695.o \
  $(JUCE_OBJDIR)/include_juce_graphics_f817e147.o \
  $(JUCE_OBJDIR)/include_juce_gui_basics_e3f79785.o \
  $(JUCE_OBJDIR)/include_juce_gui_extra_6dee1c1a.o \
  $(JUCE_OBJDIR)/include_juce_opengl_a8a032b.o \

.PHONY: clean all strip Standalone

all : Standalone

Standalone : $(JUCE_OUTDIR)/$(JUCE_TARGET_STANDALONE_PLUGIN)


$(JUCE_OUTDIR)/$(JUCE_TARGET_STANDALONE_PLUGIN) : $(OBJECTS_STANDALONE_PLUGIN) $(RESOURCES) $(JUCE_OUTDIR)/$(JUCE_TARGET_SHARED_CODE)
	@command -v pkg-config >/dev/null 2>&1 || { echo >&2 "pkg-config not installed. Please, install it."; exit 1; }
	@pkg-config --print-errors alsa x11 xinerama xext freetype2 webkit2gtk-4.0 gtk+-x11-3.0 libcurl
	@echo Linking "Fuzzface - Standalone Plugin"
	-$(V_AT)mkdir -p $(JUCE_BINDIR)
	-$(V_AT)mkdir -p $(JUCE_LIBDIR)
	-$(V_AT)mkdir -p $(JUCE_OUTDIR)
	$(V_AT)$(CXX) -o $(JUCE_OUTDIR)/$(JUCE_TARGET_STANDALONE_PLUGIN) $(OBJECTS_STANDALONE_PLUGIN) $(JUCE_OUTDIR)/$(JUCE_TARGET_SHARED_CODE) $(JUCE_LDFLAGS) $(JUCE_LDFLAGS_STANDALONE_PLUGIN) $(RESOURCES) $(TARGET_ARCH)

$(JUCE_OUTDIR)/$(JUCE_TARGET_SHARED_CODE) : $(OBJECTS_SHARED_CODE) $(RESOURCES)
	@command -v pkg-config >/dev/null 2>&1 || { echo >&2 "pkg-config not installed. Please, install it."; exit 1; }
	@pkg-config --print-errors alsa x11 xinerama xext freetype2 webkit2gtk-4.0 gtk+-x11-3.0 libcurl
	@echo Linking "Fuzzface - Shared Code"
	-$(V_AT)mkdir -p $(JUCE_BINDIR)
	-$(V_AT)mkdir -p $(JUCE_LIBDIR)
	-$(V_AT)mkdir -p $(JUCE_OUTDIR)
	$(V_AT)$(AR) -rcs $(JUCE_OUTDIR)/$(JUCE_TARGET_SHARED_CODE) $(OBJECTS_SHARED_CODE)

$(JUCE_OBJDIR)/include_juce_audio_plugin_client_Standalone_1a871192.o: ../../JuceLibraryCode/include_juce_audio_plugin_client_Standalone.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_audio_plugin_client_Standalone.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_STANDALONE_PLUGIN) $(JUCE_CFLAGS_STANDALONE_PLUGIN) -o "$@" -c "$<"

$(JUCE_OBJDIR)/amd_1_1494b58.o: ../../Libraries/AMD/Source/amd_1.c
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling amd_1.c"
	$(V_AT)$(CC) $(JUCE_CFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/amd_2_1494f19.o: ../../Libraries/AMD/Source/amd_2.c
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling amd_2.c"
	$(V_AT)$(CC) $(JUCE_CFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/amd_aat_d6dfb23b.o: ../../Libraries/AMD/Source/amd_aat.c
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling amd_aat.c"
	$(V_AT)$(CC) $(JUCE_CFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/amd_control_30e4b804.o: ../../Libraries/AMD/Source/amd_control.c
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling amd_control.c"
	$(V_AT)$(CC) $(JUCE_CFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/amd_defaults_ee287a15.o: ../../Libraries/AMD/Source/amd_defaults.c
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling amd_defaults.c"
	$(V_AT)$(CC) $(JUCE_CFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/amd_dump_b4cb837.o: ../../Libraries/AMD/Source/amd_dump.c
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling amd_dump.c"
	$(V_AT)$(CC) $(JUCE_CFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/amd_global_c946b6a6.o: ../../Libraries/AMD/Source/amd_global.c
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling amd_global.c"
	$(V_AT)$(CC) $(JUCE_CFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/amd_info_136f1c71.o: ../../Libraries/AMD/Source/amd_info.c
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling amd_info.c"
	$(V_AT)$(CC) $(JUCE_CFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/amd_order_9e8d7635.o: ../../Libraries/AMD/Source/amd_order.c
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling amd_order.c"
	$(V_AT)$(CC) $(JUCE_CFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/amd_post_tree_1b697604.o: ../../Libraries/AMD/Source/amd_post_tree.c
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling amd_post_tree.c"
	$(V_AT)$(CC) $(JUCE_CFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/amd_postorder_659e6095.o: ../../Libraries/AMD/Source/amd_postorder.c
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling amd_postorder.c"
	$(V_AT)$(CC) $(JUCE_CFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/amd_preprocess_f7034c2f.o: ../../Libraries/AMD/Source/amd_preprocess.c
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling amd_preprocess.c"
	$(V_AT)$(CC) $(JUCE_CFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/amd_valid_f4490b63.o: ../../Libraries/AMD/Source/amd_valid.c
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling amd_valid.c"
	$(V_AT)$(CC) $(JUCE_CFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/btf_maxtrans_dc4fa887.o: ../../Libraries/BTF/Source/btf_maxtrans.c
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling btf_maxtrans.c"
	$(V_AT)$(CC) $(JUCE_CFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/btf_order_b7f53cb5.o: ../../Libraries/BTF/Source/btf_order.c
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling btf_order.c"
	$(V_AT)$(CC) $(JUCE_CFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/btf_strongcomp_2e1bd2e9.o: ../../Libraries/BTF/Source/btf_strongcomp.c
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling btf_strongcomp.c"
	$(V_AT)$(CC) $(JUCE_CFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/colamd_acf415a0.o: ../../Libraries/COLAMD/Source/colamd.c
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling colamd.c"
	$(V_AT)$(CC) $(JUCE_CFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/klu_56af96e6.o: ../../Libraries/KLU/Source/klu.c
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling klu.c"
	$(V_AT)$(CC) $(JUCE_CFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/klu_analyze_8ce64ab3.o: ../../Libraries/KLU/Source/klu_analyze.c
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling klu_analyze.c"
	$(V_AT)$(CC) $(JUCE_CFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/klu_analyze_given_c20ff731.o: ../../Libraries/KLU/Source/klu_analyze_given.c
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling klu_analyze_given.c"
	$(V_AT)$(CC) $(JUCE_CFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/klu_defaults_7047ef95.o: ../../Libraries/KLU/Source/klu_defaults.c
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling klu_defaults.c"
	$(V_AT)$(CC) $(JUCE_CFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/klu_diagnostics_2d1d6613.o: ../../Libraries/KLU/Source/klu_diagnostics.c
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling klu_diagnostics.c"
	$(V_AT)$(CC) $(JUCE_CFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/klu_dump_2682edb7.o: ../../Libraries/KLU/Source/klu_dump.c
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling klu_dump.c"
	$(V_AT)$(CC) $(JUCE_CFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/klu_extract_e2bad0a8.o: ../../Libraries/KLU/Source/klu_extract.c
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling klu_extract.c"
	$(V_AT)$(CC) $(JUCE_CFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/klu_factor_2e89c6d2.o: ../../Libraries/KLU/Source/klu_factor.c
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling klu_factor.c"
	$(V_AT)$(CC) $(JUCE_CFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/klu_free_numeric_4c4387d.o: ../../Libraries/KLU/Source/klu_free_numeric.c
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling klu_free_numeric.c"
	$(V_AT)$(CC) $(JUCE_CFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/klu_free_symbolic_6a04ecc.o: ../../Libraries/KLU/Source/klu_free_symbolic.c
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling klu_free_symbolic.c"
	$(V_AT)$(CC) $(JUCE_CFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/klu_kernel_22c81640.o: ../../Libraries/KLU/Source/klu_kernel.c
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling klu_kernel.c"
	$(V_AT)$(CC) $(JUCE_CFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/klu_memory_ea166604.o: ../../Libraries/KLU/Source/klu_memory.c
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling klu_memory.c"
	$(V_AT)$(CC) $(JUCE_CFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/klu_refactor_ae035685.o: ../../Libraries/KLU/Source/klu_refactor.c
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling klu_refactor.c"
	$(V_AT)$(CC) $(JUCE_CFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/klu_scale_a3f6e3b1.o: ../../Libraries/KLU/Source/klu_scale.c
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling klu_scale.c"
	$(V_AT)$(CC) $(JUCE_CFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/klu_solve_b9109966.o: ../../Libraries/KLU/Source/klu_solve.c
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling klu_solve.c"
	$(V_AT)$(CC) $(JUCE_CFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/klu_sort_3fc966e1.o: ../../Libraries/KLU/Source/klu_sort.c
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling klu_sort.c"
	$(V_AT)$(CC) $(JUCE_CFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/klu_tsolve_a916cece.o: ../../Libraries/KLU/Source/klu_tsolve.c
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling klu_tsolve.c"
	$(V_AT)$(CC) $(JUCE_CFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/SuiteSparse_config_58fabece.o: ../../Libraries/SuiteSparse_config/SuiteSparse_config.c
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling SuiteSparse_config.c"
	$(V_AT)$(CC) $(JUCE_CFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ScopeComponent_11623c12.o: ../../Source/ScopeComponent.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling ScopeComponent.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/SliderClass_9764dbf8.o: ../../Source/SliderClass.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling SliderClass.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/PluginProcessor_a059e380.o: ../../Source/PluginProcessor.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling PluginProcessor.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/PluginEditor_94d4fb09.o: ../../Source/PluginEditor.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling PluginEditor.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/klu_solver_e0f4616c.o: ../../Source/engine/klu_solver.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling klu_solver.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/patch_static_ea5f4a73.o: ../../Source/engine/patch_static.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling patch_static.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/junctions_c30eb17b.o: ../../Source/engine/junctions.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling junctions.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/patch_82067c9.o: ../../Source/patch.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling patch.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/BinaryData_ce4232d4.o: ../../JuceLibraryCode/BinaryData.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling BinaryData.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_audio_basics_8a4e984a.o: ../../JuceLibraryCode/include_juce_audio_basics.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_audio_basics.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_audio_devices_63111d02.o: ../../JuceLibraryCode/include_juce_audio_devices.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_audio_devices.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_audio_formats_15f82001.o: ../../JuceLibraryCode/include_juce_audio_formats.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_audio_formats.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_audio_plugin_client_utils_e32edaee.o: ../../JuceLibraryCode/include_juce_audio_plugin_client_utils.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_audio_plugin_client_utils.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_audio_processors_10c03666.o: ../../JuceLibraryCode/include_juce_audio_processors.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_audio_processors.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_audio_utils_9f9fb2d6.o: ../../JuceLibraryCode/include_juce_audio_utils.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_audio_utils.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_core_f26d17db.o: ../../JuceLibraryCode/include_juce_core.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_core.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_cryptography_8cb807a8.o: ../../JuceLibraryCode/include_juce_cryptography.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_cryptography.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_data_structures_7471b1e3.o: ../../JuceLibraryCode/include_juce_data_structures.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_data_structures.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_events_fd7d695.o: ../../JuceLibraryCode/include_juce_events.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_events.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_graphics_f817e147.o: ../../JuceLibraryCode/include_juce_graphics.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_graphics.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_gui_basics_e3f79785.o: ../../JuceLibraryCode/include_juce_gui_basics.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_gui_basics.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_gui_extra_6dee1c1a.o: ../../JuceLibraryCode/include_juce_gui_extra.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_gui_extra.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_opengl_a8a032b.o: ../../JuceLibraryCode/include_juce_opengl.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_opengl.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_SHARED_CODE) $(JUCE_CFLAGS_SHARED_CODE) -o "$@" -c "$<"

clean:
	@echo Cleaning Fuzzface
	$(V_AT)$(CLEANCMD)

strip:
	@echo Stripping Fuzzface
	-$(V_AT)$(STRIP) --strip-unneeded $(JUCE_OUTDIR)/$(TARGET)

-include $(OBJECTS_STANDALONE_PLUGIN:%.o=%.d)
-include $(OBJECTS_SHARED_CODE:%.o=%.d)
