<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\DICOM;

use PHPExiftool\Driver\AbstractTag;

class DigitalSignaturesSequence extends AbstractTag
{

    protected $Id = 'FFFA,FFFA';

    protected $Name = 'DigitalSignaturesSequence';

    protected $FullName = 'DICOM::Main';

    protected $GroupName = 'DICOM';

    protected $g0 = 'DICOM';

    protected $g1 = 'DICOM';

    protected $g2 = 'Image';

    protected $Type = '?';

    protected $Writable = false;

    protected $Description = 'Digital Signatures Sequence';

}
