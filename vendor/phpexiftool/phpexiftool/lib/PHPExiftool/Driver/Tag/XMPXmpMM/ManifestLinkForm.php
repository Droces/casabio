<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\XMPXmpMM;

use PHPExiftool\Driver\AbstractTag;

class ManifestLinkForm extends AbstractTag
{

    protected $Id = 'ManifestLinkForm';

    protected $Name = 'ManifestLinkForm';

    protected $FullName = 'XMP::xmpMM';

    protected $GroupName = 'XMP-xmpMM';

    protected $g0 = 'XMP';

    protected $g1 = 'XMP-xmpMM';

    protected $g2 = 'Other';

    protected $Type = 'string';

    protected $Writable = true;

    protected $Description = 'Manifest Link Form';

    protected $flag_List = true;

}
